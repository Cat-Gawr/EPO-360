#include "xenia/vfs/devices/stfs_container_entry.h"
#include "xenia/base/math.h"
#include "xenia/vfs/devices/stfs_container_file.h"

#include <map>

namespace xe {
namespace vfs {

StfsContainerEntry::StfsContainerEntry(Device* device, Entry* parent,
                                       const std::string_view path,
                                       MultiFileHandles* files)
    : Entry(device, parent, path),
      files_(files),
      data_offset_(0),
      data_size_(0),
      block_(0) {}

StfsContainerEntry::~StfsContainerEntry() = default;

std::unique_ptr<StfsContainerEntry> StfsContainerEntry::Create(
    Device* device, Entry* parent, const std::string_view name,
    MultiFileHandles* files) {
  auto path = xe::utf8::join_guest_paths(parent->path(), name);
  auto entry =
      std::make_unique<StfsContainerEntry>(device, parent, path, files);

  return std::move(entry);
}

X_STATUS StfsContainerEntry::Open(uint32_t desired_access, File** out_file) {
  *out_file = new StfsContainerFile(desired_access, this);
  return X_STATUS_SUCCESS;
}

}  // namespace vfs
}  // namespace xe
