//
// Created by huhua on 2023/4/12.
//

#include "../include/unity_fs_unpack/unity_file.h"

UnityFile::UnityFile(reader_util::FileReader *file_reader): file_reader_(file_reader) {
  this->parse_();
}

void UnityFile::parse_() {
  this->parse(*this->file_reader_);
}

void UnityFile::parse(reader_util::FileReader &file_reader) {
  metaSize_ = file_reader_->readUInt32();
  fileSize_ = file_reader_->readUInt32();
  version_ = file_reader_->readUInt32();
  dataOffset_ = file_reader_->readUInt32();

  endian_ = (unsigned char)file_reader_->readByte();
  file_reader_->read(reserved_, sizeof(reserved_));
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
  for (int i = 0; i < typeCount_; ++i) {
    SerializedType serialized_type((int)this->version_);
    serialized_type.parse(*file_reader_);
    this->serializedTypes_.push_back(serialized_type);
  }

  objectCount_ = (int)file_reader_->readUInt32();
}

std::string UnityFile::getUnityVersion() {
  return this->unityVersion_;
}

int UnityFile::getEndian() {
  return this->endian_;
}

int UnityFile::getObjectCount() {
  return objectCount_;
}

int UnityFile::getTypeCount() {
  return this->typeCount_;
}

int UnityFile::getTargetPlatform() {
  return this->targetPlatform_;
}

int UnityFile::getVersion() {
  return this->version_;
}

bool UnityFile::isEnableTypeTree() {
  return this->enableTypeTree_;
}

std::vector<SerializedType> UnityFile::getSerializedTypes() {
  return this->serializedTypes_;
}
