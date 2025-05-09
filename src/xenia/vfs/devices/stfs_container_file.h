#ifndef XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_
#define XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_

#include "xenia/vfs/file.h"

#include "xenia/xbox.h"

namespace xe {
namespace vfs {

class StfsContainerEntry;

class StfsContainerFile : public File {
 public:
  StfsContainerFile(uint32_t file_access, StfsContainerEntry* entry);
  ~StfsContainerFile() override;

  void Destroy() override;

  X_STATUS ReadSync(void* buffer, size_t buffer_length, size_t byte_offset,
                    size_t* out_bytes_read) override;
  X_STATUS WriteSync(const void* buffer, size_t buffer_length,
                     size_t byte_offset, size_t* out_bytes_written) override {
    return X_STATUS_ACCESS_DENIED;
  }
  X_STATUS SetLength(size_t length) override { return X_STATUS_ACCESS_DENIED; }

 private:
  StfsContainerEntry* entry_;
};

}  // namespace vfs
}  // namespace xe

#endif  // XENIA_VFS_DEVICES_STFS_CONTAINER_FILE_H_
