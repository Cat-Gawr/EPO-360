
#ifndef XENIA_KERNEL_XBDM_XBDM_ORDINALS_H_
#define XENIA_KERNEL_XBDM_XBDM_ORDINALS_H_

#include "xenia/cpu/export_resolver.h"

// Build an ordinal enum to make it easy to lookup ordinals.
#include "xenia/kernel/util/ordinal_table_pre.inc"
namespace ordinals {
enum {
#include "xenia/kernel/xbdm/xbdm_table.inc"
};
}  // namespace ordinals
#include "xenia/kernel/util/ordinal_table_post.inc"

#endif  // XENIA_KERNEL_XBDM_XBDM_ORDINALS_H_
