//
// Created by huhua on 2023/4/12.
//

#ifndef UNITY_FS_UNPACK_SRC_UNITY_FILE_H_
#define UNITY_FS_UNPACK_SRC_UNITY_FILE_H_

#include "./i_unity_file.h"

#include <reader_util/reader_util.h>

class UnityFile: public IUnityFile {
 public:
  explicit UnityFile(reader_util::FileReader* file_reader);

 public:
  std::string getUnityVersion();
  int getEndian() override;
  int getObjectCount() override;
  uint32_t getTypeCount();

 private:
  uint32_t metaSize_ = 0;
  uint32_t fileSize_ = 0;
  uint32_t version_ = 0;
  uint32_t dataOffset_ = 0;
  int endian_ = 0;
  char reserved_[3];
  uint32_t targetPlatform_ = 0;
  bool enableTypeTree_ = false;
  std::string unityVersion_;
  /**
   * for now, I don't know what's the type count, but we will goon
   */
  uint32_t typeCount_ = 0;
  /**
   * 文件个数
   */
  int fileCount_ = 0;
  reader_util::FileReader* file_reader_ = nullptr;
};

#endif //UNITY_FS_UNPACK_SRC_UNITY_FILE_H_
