//
// Hello World client
// Connects REQ socket to tcp://localhost:5555
// Sends "Hello" to server, expects "World" back
//
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
void *context = zmq_init (1);

// Socket to talk to server
printf ("Connecting to test_rep server... \n");
void *requester = zmq_socket (context, ZMQ_SUB);
zmq_connect (requester, "tcp://127.0.0.1:5555");
zmq_setsockopt(requester, ZMQ_SUBSCRIBE, "", 0);

while(1) {
    zmq_msg_t reply;
    zmq_msg_init (&reply);
    zmq_recv (requester, &reply, 0);
    printf ("Received %s \n", zmq_msg_data(&reply) );
    zmq_msg_close (&reply);
}
zmq_close (requester);
zmq_term (context);
return 0;
}

