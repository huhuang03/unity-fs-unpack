//
// Created by huhua on 2023/4/12.
//

#ifndef UNITY_FS_UNPACK_SRC_MODEL_TYPE_TREE_NODE_H_
#define UNITY_FS_UNPACK_SRC_MODEL_TYPE_TREE_NODE_H_

#include <string>
#include <vector>
#include "../../include/unity_fs_unpack/core/i_parseable.h"

class TypeTreeNode: public IParseable {
 public:
  explicit TypeTreeNode(int level);
 private:
  void parse(reader_util::FileReader &file_reader) override;
  std::vector<TypeTreeNode> children;

 private:
  int level_;

  std::string type_;
  std::string name_;
  uint32_t byteSize_;
  uint32_t index_;
  uint32_t typeFlags_;
  uint32_t version_;
  uint32_t metaFlag_;
  uint32_t typeStrOffset_;
  uint32_t nameStrOffset_;
  uint32_t childCount_;
  uint64_t refTypeHash_;
};

#endif //UNITY_FS_UNPACK_SRC_MODEL_TYPE_TREE_NODE_H_
