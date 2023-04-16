#include "reader_util/file_reader.h"
#include "unity_fs_unpack/model/object.h"
//
// Created by huhua on 2023/4/15.
//

void Object::parse(reader_util::FileReader &file_reader) {
  file_reader.align(4);
  this->pathId_ = file_reader.readUInt64();
  this->byteStart_ = file_reader.readUInt32();
  this->byteSize_ = file_reader.readUInt32();
  this->typeId_ = file_reader.readUInt32();
}

std::ostream &operator<<(std::ostream &os, const Object &object) {
  os << "Object(" << "pathId: " << object.pathId_ << ", byteStart: " << object.byteStart_ << ", byteSize: " << object.byteSize_  << ", typeId: " << object.typeId_ << ")";
  return os;
}
