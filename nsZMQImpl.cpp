#define __STDC_LIMIT_MACROS
#include "nsZMQImpl.h"
#include <stdio.h>
#include <stdlib.h>

NS_IMPL_ISUPPORTS1(nsZMQ, nsIZMQ)

nsZMQ::nsZMQ()
{
  /* member initializers and constructor code */
    this->ctx = NULL;
    this->socket = NULL;
}

nsZMQ::~nsZMQ()
{
  /* destructor code */

    int rc = -1 ;
    if (this->socket) {
        // free socket
        rc = zmq_close(this->socket);
    }

    if (this->ctx) {
        // free context
        rc = zmq_term(this->ctx);
    }

}

/* readonly attribute AUTF8String lastErrorString; */
NS_IMETHODIMP nsZMQ::GetLastErrorString(nsACString & aLastErrorString)
{
    if (this->ctx == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    int lastErrNo = zmq_errno();

    aLastErrorString.Assign(zmq_strerror (lastErrNo));

    return NS_OK;
}

/* readonly attribute int32_t lastErrorNo; */
NS_IMETHODIMP nsZMQ::GetLastErrorNo(int32_t *aLastErrorNo)
{

    if (this->ctx == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    *aLastErrorNo = zmq_errno();

    return NS_OK;
}

/* readonly attribute AUTF8String version; */
NS_IMETHODIMP nsZMQ::GetVersion(nsACString & aVersion)
{

    int major, minor, patch;
    zmq_version (&major, &minor, &patch);

    char ver[100];
    sprintf(ver, "%d.%d.%d", major, minor, patch);
    aVersion.Assign((const char*)ver, strlen(ver));

    return NS_OK;
}

/* void init (in int32_t io_threads); */
NS_IMETHODIMP nsZMQ::Init(int32_t io_threads)
{

    this->ctx = zmq_init (io_threads);

    if (this->ctx == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    return NS_OK;
}

/* int32_t term (); */
NS_IMETHODIMP nsZMQ::Term(int32_t *_retval)
{

    if (this->ctx == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    *_retval = zmq_term (this->ctx);

    if (*_retval != 0) {
        return NS_ERROR_FAILURE;
    }

    return NS_OK;
}

/* void socket (in short socket_type); */
NS_IMETHODIMP nsZMQ::Socket(int16_t socket_type)
{

    if (this->ctx == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    this->socket = zmq_socket (this->ctx, socket_type);

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    return NS_OK;
}

/* int32_t close (); */
NS_IMETHODIMP nsZMQ::Close(int32_t *_retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    *_retval = zmq_close (this->socket);
    if (*_retval != 0) {
        return NS_ERROR_FAILURE;
    }

    return NS_OK;
}

/* int32_t setsockopt (in int32_t option, in AUTF8String optval); */
NS_IMETHODIMP nsZMQ::Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    switch (option) {

        case ZMQ_SWAP:
        case ZMQ_RATE:
        case ZMQ_RECOVERY_IVL:
        case ZMQ_RECOVERY_IVL_MSEC:
        case ZMQ_MCAST_LOOP:
        case ZMQ_LINGER:
        case ZMQ_RECONNECT_IVL:
        case ZMQ_RECONNECT_IVL_MAX:
        case ZMQ_BACKLOG:
        case ZMQ_TYPE:
        {
            int64_t value;
            value = (int64_t) strtol(optval.BeginReading(), NULL, 10);

            *_retval = zmq_setsockopt(this->socket, option, &value, sizeof(int64_t));
        }
        break;

        case ZMQ_IDENTITY:
        case ZMQ_SUBSCRIBE:
        case ZMQ_UNSUBSCRIBE:
        {
            *_retval = zmq_setsockopt (this->socket, option, optval.BeginReading(), optval.Length());
        }
        break;

        case ZMQ_HWM:
        case ZMQ_AFFINITY:
        case ZMQ_SNDBUF:
        case ZMQ_RCVBUF:
        {
            u_int64_t value;
            value = (u_int64_t) strtoul(optval.BeginReading(), NULL, 10);
            if (value < 0) return NS_ERROR_FAILURE;

            *_retval = zmq_setsockopt(this->socket, option, &value, sizeof(u_int64_t));
        }
        break;

        default:
        {

            return NS_ERROR_FAILURE;
        }
        break;

    }

    return NS_OK;
}

/* AUTF8String getsockopt (in int32_t option); */
NS_IMETHODIMP nsZMQ::Getsockopt(int32_t option, nsACString & _retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    switch (option) {

        case ZMQ_SWAP:
        case ZMQ_RATE:
        case ZMQ_RECOVERY_IVL:
        case ZMQ_RECOVERY_IVL_MSEC:
        case ZMQ_MCAST_LOOP:
        case ZMQ_LINGER:
        case ZMQ_RECONNECT_IVL:
        case ZMQ_RECONNECT_IVL_MAX:
        case ZMQ_BACKLOG:
        case ZMQ_TYPE:
        {
            int64_t value;
            size_t *len;

            *len = (size_t) sizeof(int64_t);
            int rc = zmq_getsockopt(this->socket, option, &value, len);

            if (rc == 0) {
                char tmp[20];
                sprintf(tmp, "%d", value);
                _retval.Assign(tmp);
            }
        }
        break;

        case ZMQ_IDENTITY:
        {

            char value[255];
            size_t *len;
            *len = 255;

            int rc = zmq_getsockopt(this->socket, option, value, len);

            if (rc == 0) {
                _retval.Assign(value);
            }
        }
        break;

        case ZMQ_HWM:
        case ZMQ_SNDBUF:
        case ZMQ_RCVBUF:
        {
            u_int64_t value;
            size_t *len;
            *len = (size_t) sizeof(u_int64_t);

            int rc = zmq_getsockopt(this->socket, option, &value, len);

            if (rc == 0) {
                char tmp[20];
                sprintf(tmp, "%d", value);
                _retval.Assign(tmp);
            }

        }
        break;

        default:
        {

            return NS_ERROR_FAILURE;
        }
        break;

    }

    return NS_OK;

}

/* int32_t bind (in AUTF8String addr); */
NS_IMETHODIMP nsZMQ::Bind(const nsACString & addr, int32_t *_retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    *_retval = zmq_bind (this->socket, addr.BeginReading());

    return NS_OK;

}

/* int32_t connect (in AUTF8String addr); */
NS_IMETHODIMP nsZMQ::Connect(const nsACString & addr, int32_t *_retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    *_retval = zmq_connect (this->socket, addr.BeginReading());

    return NS_OK;

}

/* int32_t send (in AUTF8String msg, [optional] in int32_t flags); */
NS_IMETHODIMP nsZMQ::Send(const nsACString & msg, int32_t flags, int32_t *_retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    zmq_msg_t zmsg;
    int rc = 0;

    rc = zmq_msg_init_size (&zmsg, msg.Length());

    memcpy(zmq_msg_data(&zmsg), msg.BeginReading(), msg.Length());

    rc = zmq_send (this->socket, &zmsg, flags);

    *_retval = rc;

    rc = zmq_msg_close(&zmsg);

    return NS_OK;
}

/* AUTF8String recv ([optional] in int32_t flags); */
NS_IMETHODIMP nsZMQ::Recv(int32_t flags, nsACString & _retval)
{

    if (this->socket == NULL) {
        return NS_ERROR_NULL_POINTER;
    }

    zmq_msg_t zmsg;

    int rc = zmq_msg_init (&zmsg);

    rc = zmq_recv (this->socket, &zmsg, flags);

    if (rc != 0 && zmq_errno() == EAGAIN) {
        zmq_msg_close(&zmsg);
    }

    if (rc == 0) {
        _retval.Assign((const char*) zmq_msg_data(&zmsg), zmq_msg_size(&zmsg));
        zmq_msg_close(&zmsg);
    }

    return NS_OK;
}

