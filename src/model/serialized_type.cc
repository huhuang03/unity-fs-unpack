//
// Created by huhua on 2023/4/12.
//

#include "../../include/unity_fs_unpack/model/serialized_type.h"

void SerializedType::parse(reader_util::FileReader &file_reader) {
  this->classId_ = file_reader.readInt32();
//  if (this->classId_ < 0 || classId_ == 114) {
//    file_reader.read(this->scriptId_, sizeof(this->scriptId_));
//  }
  if (this->version_ >= 16) {
    // false
    this->strippedType_ = file_reader.readByte();
  }
  if (this->version_ >= 17) {
    // -1
    this->scriptTypeIndex = file_reader.readInt16();
  }
  file_reader.read(this->oldTypeHash_, sizeof(this->oldTypeHash_));
}

std::ostream &operator<<(std::ostream& os, const SerializedType &serialized_type) {
  os << "SerializedType(classId: " << serialized_type.classId_ << ")";
  return os;
}

SerializedType::SerializedType(int version): version_(version) {}
