#include "mozilla-config.h"
#include "nsZMQImpl.h"

#include "mozilla/ModuleUtils.h"
#include "nsIClassInfoImpl.h"


NS_GENERIC_FACTORY_CONSTRUCTOR(nsZMQ)
NS_DEFINE_NAMED_CID(ZMQ_CID);

static const mozilla::Module::CIDEntry kZMQCIDs[] = {
    { &kZMQ_CID, false, NULL, nsZMQConstructor },
    { NULL }
};

static const mozilla::Module::ContractIDEntry kZMQContracts[] = {
    { ZMQ_CONTRACTID, &kZMQ_CID },
    { NULL }
};

static const mozilla::Module::CategoryEntry kZMQCategories[] = {
    { NULL }
};

static const mozilla::Module kZMQModule = {
    mozilla::Module::kVersion,
    kZMQCIDs,
    kZMQContracts,
    kZMQCategories
};


// The following line implements the one-and-only "NSModule" symbol exported from this
// shared library.
NSMODULE_DEFN(ZMQModule) = &kZMQModule;

// The following line implements the one-and-only "NSGetModule" symbol
// for compatibility with mozilla 1.9.2. You should only use this
// if you need a binary which is backwards-compatible and if you use
// interfaces carefully across multiple versions.
NS_IMPL_MOZILLA192_NSGETMODULE(&kZMQModule)

