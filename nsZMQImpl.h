/*
 * File:   nsZMQ.h
 * Author: rack
 *
 * Created on 2010年2月13日, 下午 2:22
 */

#ifndef _NS_ZMQ_H
#define	_NS_ZMQ_H

#include "nsIZMQ.h"

//1a51026d-b770-48fb-a9ca-90969bb9a7cb"
#define ZMQ_CID \
  { 0x1a51026d, 0xb770, 0x48fb, \
  { 0xa9, 0xca, 0x90, 0x96, 0x9b, 0xb9, 0xa7, 0xcb } }

#define ZMQ_CONTRACTID "@racklin.gmail.com/zmq;1"

class nsZMQ : public nsIZMQ
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZMQ

  nsZMQ();

private:
  ~nsZMQ();

  void *ctx;
  void *socket;


protected:
  /* additional members */
};


#endif	/* _NS_ZMQ_H */

