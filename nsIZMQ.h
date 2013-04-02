/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM nsIZMQ.idl
 */

#ifndef __gen_nsIZMQ_h__
#define __gen_nsIZMQ_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsStringAPI.h"
#include <zmq.h>

/* starting interface:    nsIZMQ */
#define NS_IZMQ_IID_STR "7a6fda00-0dd0-404c-8f25-89ba42ed2577"

#define NS_IZMQ_IID \
  {0x7a6fda00, 0x0dd0, 0x404c, \
    { 0x8f, 0x25, 0x89, 0xba, 0x42, 0xed, 0x25, 0x77 }}

class NS_NO_VTABLE nsIZMQ : public nsISupports {
 public:

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZMQ_IID)

    /*
  enum {
    ZMQ_PAIR = 0,
    ZMQ_PUB = 1,
    ZMQ_SUB = 2,
    ZMQ_REQ = 3,
    ZMQ_REP = 4,
    ZMQ_DEALER = 5,
    ZMQ_ROUTER = 6,
    ZMQ_PULL = 7,
    ZMQ_PUSH = 8,
    ZMQ_XPUB = 9,
    ZMQ_XSUB = 10,
    ZMQ_HWM = 1,
    ZMQ_SWAP = 3,
    ZMQ_AFFINITY = 4,
    ZMQ_IDENTITY = 5,
    ZMQ_SUBSCRIBE = 6,
    ZMQ_UNSUBSCRIBE = 7,
    ZMQ_RATE = 8,
    ZMQ_RECOVERY_IVL = 9,
    ZMQ_MCAST_LOOP = 10,
    ZMQ_SNDBUF = 11,
    ZMQ_RCVBUF = 12,
    ZMQ_RCVMORE = 13,
    ZMQ_FD = 14,
    ZMQ_EVENTS = 15,
    ZMQ_TYPE = 16,
    ZMQ_LINGER = 17,
    ZMQ_RECONNECT_IVL = 18,
    ZMQ_BACKLOG = 19,
    ZMQ_RECOVERY_IVL_MSEC = 20,
    ZMQ_RECONNECT_IVL_MAX = 21,
    ZMQ_RCVTIMEO = 27,
    ZMQ_SNDTIMEO = 28,
    ZMQ_NOBLOCK = 1,
    ZMQ_SNDMORE = 2,
    ZMQ_POLLIN = 1,
    ZMQ_POLLOUT = 2,
    ZMQ_POLLERR = 4
  };*/

  /* readonly attribute AUTF8String lastErrorString; */
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) = 0;

  /* readonly attribute int32_t lastErrorNo; */
  NS_IMETHOD GetLastErrorNo(int32_t *aLastErrorNo) = 0;

  /* readonly attribute AUTF8String version; */
  NS_IMETHOD GetVersion(nsACString & aVersion) = 0;

  /* void init (in int32_t io_threads); */
  NS_IMETHOD Init(int32_t io_threads) = 0;

  /* int32_t term (); */
  NS_IMETHOD Term(int32_t *_retval) = 0;

  /* void socket (in short socket_type); */
  NS_IMETHOD Socket(int16_t socket_type) = 0;

  /* int32_t close (); */
  NS_IMETHOD Close(int32_t *_retval) = 0;

  /* int32_t setsockopt (in int32_t option, in AUTF8String optval); */
  NS_IMETHOD Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval) = 0;

  /* AUTF8String getsockopt (in int32_t option); */
  NS_IMETHOD Getsockopt(int32_t option, nsACString & _retval) = 0;

  /* int32_t bind (in AUTF8String addr); */
  NS_IMETHOD Bind(const nsACString & addr, int32_t *_retval) = 0;

  /* int32_t connect (in AUTF8String addr); */
  NS_IMETHOD Connect(const nsACString & addr, int32_t *_retval) = 0;

  /* int32_t send (in AUTF8String msg, [optional] in int32_t flags); */
  NS_IMETHOD Send(const nsACString & msg, int32_t flags, int32_t *_retval) = 0;

  /* AUTF8String recv ([optional] in int32_t flags); */
  NS_IMETHOD Recv(int32_t flags, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZMQ, NS_IZMQ_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZMQ \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString); \
  NS_IMETHOD GetLastErrorNo(int32_t *aLastErrorNo); \
  NS_IMETHOD GetVersion(nsACString & aVersion); \
  NS_IMETHOD Init(int32_t io_threads); \
  NS_IMETHOD Term(int32_t *_retval); \
  NS_IMETHOD Socket(int16_t socket_type); \
  NS_IMETHOD Close(int32_t *_retval); \
  NS_IMETHOD Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval); \
  NS_IMETHOD Getsockopt(int32_t option, nsACString & _retval); \
  NS_IMETHOD Bind(const nsACString & addr, int32_t *_retval); \
  NS_IMETHOD Connect(const nsACString & addr, int32_t *_retval); \
  NS_IMETHOD Send(const nsACString & msg, int32_t flags, int32_t *_retval); \
  NS_IMETHOD Recv(int32_t flags, nsACString & _retval);

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZMQ(_to) \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return _to GetLastErrorString(aLastErrorString); } \
  NS_IMETHOD GetLastErrorNo(int32_t *aLastErrorNo) { return _to GetLastErrorNo(aLastErrorNo); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD Init(int32_t io_threads) { return _to Init(io_threads); } \
  NS_IMETHOD Term(int32_t *_retval) { return _to Term(_retval); } \
  NS_IMETHOD Socket(int16_t socket_type) { return _to Socket(socket_type); } \
  NS_IMETHOD Close(int32_t *_retval) { return _to Close(_retval); } \
  NS_IMETHOD Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval) { return _to Setsockopt(option, optval, _retval); } \
  NS_IMETHOD Getsockopt(int32_t option, nsACString & _retval) { return _to Getsockopt(option, _retval); } \
  NS_IMETHOD Bind(const nsACString & addr, int32_t *_retval) { return _to Bind(addr, _retval); } \
  NS_IMETHOD Connect(const nsACString & addr, int32_t *_retval) { return _to Connect(addr, _retval); } \
  NS_IMETHOD Send(const nsACString & msg, int32_t flags, int32_t *_retval) { return _to Send(msg, flags, _retval); } \
  NS_IMETHOD Recv(int32_t flags, nsACString & _retval) { return _to Recv(flags, _retval); }

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZMQ(_to) \
  NS_IMETHOD GetLastErrorString(nsACString & aLastErrorString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastErrorString(aLastErrorString); } \
  NS_IMETHOD GetLastErrorNo(int32_t *aLastErrorNo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastErrorNo(aLastErrorNo); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD Init(int32_t io_threads) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(io_threads); } \
  NS_IMETHOD Term(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Term(_retval); } \
  NS_IMETHOD Socket(int16_t socket_type) { return !_to ? NS_ERROR_NULL_POINTER : _to->Socket(socket_type); } \
  NS_IMETHOD Close(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(_retval); } \
  NS_IMETHOD Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Setsockopt(option, optval, _retval); } \
  NS_IMETHOD Getsockopt(int32_t option, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Getsockopt(option, _retval); } \
  NS_IMETHOD Bind(const nsACString & addr, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Bind(addr, _retval); } \
  NS_IMETHOD Connect(const nsACString & addr, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Connect(addr, _retval); } \
  NS_IMETHOD Send(const nsACString & msg, int32_t flags, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(msg, flags, _retval); } \
  NS_IMETHOD Recv(int32_t flags, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Recv(flags, _retval); }

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZMQ : public nsIZMQ
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZMQ

  nsZMQ();

private:
  ~nsZMQ();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZMQ, nsIZMQ)

nsZMQ::nsZMQ()
{
  /* member initializers and constructor code */
}

nsZMQ::~nsZMQ()
{
  /* destructor code */
}

/* readonly attribute AUTF8String lastErrorString; */
NS_IMETHODIMP nsZMQ::GetLastErrorString(nsACString & aLastErrorString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t lastErrorNo; */
NS_IMETHODIMP nsZMQ::GetLastErrorNo(int32_t *aLastErrorNo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String version; */
NS_IMETHODIMP nsZMQ::GetVersion(nsACString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in int32_t io_threads); */
NS_IMETHODIMP nsZMQ::Init(int32_t io_threads)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t term (); */
NS_IMETHODIMP nsZMQ::Term(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void socket (in short socket_type); */
NS_IMETHODIMP nsZMQ::Socket(int16_t socket_type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t close (); */
NS_IMETHODIMP nsZMQ::Close(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t setsockopt (in int32_t option, in AUTF8String optval); */
NS_IMETHODIMP nsZMQ::Setsockopt(int32_t option, const nsACString & optval, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getsockopt (in int32_t option); */
NS_IMETHODIMP nsZMQ::Getsockopt(int32_t option, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t bind (in AUTF8String addr); */
NS_IMETHODIMP nsZMQ::Bind(const nsACString & addr, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t connect (in AUTF8String addr); */
NS_IMETHODIMP nsZMQ::Connect(const nsACString & addr, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t send (in AUTF8String msg, [optional] in int32_t flags); */
NS_IMETHODIMP nsZMQ::Send(const nsACString & msg, int32_t flags, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String recv ([optional] in int32_t flags); */
NS_IMETHODIMP nsZMQ::Recv(int32_t flags, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIZMQ_h__ */
