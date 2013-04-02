// Hello World server

#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main (void)
{

void *context = zmq_init (1);

// Socket to talk to clients
void *responder = zmq_socket (context, ZMQ_REP);
zmq_bind (responder, "tcp://127.0.0.1:5555");

while (1) {
// Wait for next request from client
zmq_msg_t request;
zmq_msg_init (&request);
zmq_recv (responder, &request, 0);
printf ("Received (%s) \n", (const char*)zmq_msg_data(&request));
zmq_msg_close (&request);

// Do some 'work'
sleep (1);

// Send reply back to client
zmq_msg_t reply;
zmq_msg_init_size (&reply, 5);
memcpy (zmq_msg_data (&reply), "World", 5);
zmq_send (responder, &reply, 0);
zmq_msg_close (&reply);
}
// We never get here but if we did, this would be how we end
zmq_close (responder);
zmq_term (context);
return 0;
}

