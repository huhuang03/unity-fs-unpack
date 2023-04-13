//
// Created by huhua on 2023/4/12.
//

#include "type_tree_node.h"

TypeTreeNode::TypeTreeNode(int level): level_(level) {}

void TypeTreeNode::parse(reader_util::FileReader &file_reader) {
  this->type_ = file_reader.readUInt32();
  this->name_ = file_reader.readString();
  this->byteSize_ = file_reader.readUInt32();
  this->index_ = file_reader.readUInt32();
  this->typeFlags_ = file_reader.readUInt32();
  this->version_ = file_reader.readUInt32();
  this->metaFlag_ = file_reader.readUInt32();
  this->childCount_ = file_reader.readUInt32();
  for (int i = 0; i < this->childCount_; ++i) {
    TypeTreeNode node(level_ + 1);
    node.parse(file_reader);
    this->children.push_back(node);
  }
}

