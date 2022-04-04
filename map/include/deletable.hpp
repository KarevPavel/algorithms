//
// Created by yacopsae on 31/03/22.
//

#pragma once

class Deletable {
 public:
  Deletable() : deleted(false) {}

  bool is_deleted() const {
	return deleted;
  }

  void _delete() {
	deleted = true;
  }

 private:
  bool deleted;
};
