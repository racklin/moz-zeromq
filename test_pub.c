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
void *responder = zmq_socket (context, ZMQ_PUB);
zmq_bind (responder, "tcp://127.0.0.1:5555");

while (1) {
// Send reply back to client
zmq_msg_t reply;
zmq_msg_init_size (&reply, 11);
memcpy (zmq_msg_data (&reply), "Hello World", 11);
zmq_send (responder, &reply, 0);
printf("Publish %s \n", zmq_msg_data(&reply));
zmq_msg_close (&reply);
sleep(1);
}
// We never get here but if we did, this would be how we end
zmq_close (responder);
zmq_term (context);
return 0;
}

