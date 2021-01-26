/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "core/error_macros.h"
#include "gdnet_address.h"
#include "gdnet_event.h"
#include "gdnet_message.h"
#include "gdnet_peer.h"
#include "penet/penet.h"

void register_gdnet3_types() {
  ClassDB::register_virtual_class<GDNetPeer>();
  ClassDB::register_virtual_class<GDNetEvent>();
  ClassDB::register_virtual_class<GDNetMessage>();
  ClassDB::register_class<GDNetHost>();
  ClassDB::register_class<GDNetAddress>();

  if (penet_initialize() != 0) print_error("Unable to initialize PENet");
}

void unregister_gdnet3_types() { penet_deinitialize(); }
