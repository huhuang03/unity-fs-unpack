//
// Created by huhua on 2023/4/12.
//

#include "../include/unity_fs_unpack/unity_file.h"

UnityFile::UnityFile(reader_util::FileReader *file_reader): file_reader_(file_reader) {
  metaSize_ = file_reader_->readUInt32();
  fileSize_ = file_reader_->readUInt32();
  version_ = file_reader_->readUInt32();
  dataOffset_ = file_reader_->readUInt32();

  endian_ = (unsigned char)file_reader_->readByte();
  file_reader->read(reserved_, sizeof(reserved_));
  if (this->endian_ == 0) {
    // how to do this?
    this->file_reader_->changeEndian(reader_util::LITTLE);
  } else {
    this->file_reader_->changeEndian(reader_util::BIG);
  }
  unityVersion_ = file_reader_->readString();

  targetPlatform_ = file_reader_->readUInt32();
  enableTypeTree_ = file_reader_->readByte() != 0;

  typeCount_ = file_reader_->readUInt32();
}

std::string UnityFile::getUnityVersion() {
  return this->unityVersion_;
}

int UnityFile::getEndian() {
  return this->endian_;
}

int UnityFile::getObjectCount() {
  return 0;
}

uint32_t UnityFile::getTypeCount() {
  return this->typeCount_;
}
