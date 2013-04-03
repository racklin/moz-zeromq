Experimental Mozilla XPCOM bindings for 0MQ
----------------------------------------
This is Mozilla XPCOM bindings for [0MQ](http://www.zeromq.org) (2.2.x recommended).


Build for Linux
----------------------------------------
Debian or Ubuntu 
Required Packages cmake / xulrunner-dev / libzmq

1. cmake .
2. make

Build for MacOSX or specified XULRunner SDK
----------------------------------------
brew install cmake pkg-config .

1. build zeromq 2.2.x.
2. download and untar xulrunner-sdk.
3. cmake -D XULRUNNER-SDK=/usr/local/xulrunner-sdk .
4. make

Install
----------------------------------------
Copy built .so and .xpt to your xulrunner application's components directory.


Examples
----------------------------------------
```
// create new zmq context
var zmqContext = Components.classes["@racklin.gmail.com/zmq;1"].createInstance(Components.interfaces.nsIZMQ);

// dump zmq version
// alert or console.log
alert(zmqContext.version);

// init zmq context with io threads number
zmqContext.init(1);

// create socket with type
zmqContext.socket(zmqContext.ZMQ_REQ);

// connect to endpoint
zmqContext.connect("tcp://127.0.0.1:5555");

// send
zmqContext.send("hello world.");

// recv
var message = zmqContext.recv();

// close socket
zmqContext.close();

// terminate context
zmqContext.term();

```

License
-----------------------------
Licensed under the [LGPL License](http://www.gnu.org/licenses/lgpl.html).

