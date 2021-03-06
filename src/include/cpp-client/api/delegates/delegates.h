/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef DELEGATES_H
#define DELEGATES_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class IDelegates : public Base {
 public:
  virtual ~IDelegates() {}

  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string blocks(const char *const identifier, const char* const query) = 0;
  virtual std::string voters(const char *const identifier, const char* const query) = 0;

 protected:
  IDelegates(Host &host, IHTTP &http) : Base(host, http) {}
};

/**/

class Delegates : public IDelegates {
 public:
  Delegates(Host &host, IHTTP &http) : IDelegates(host, http) {}

  std::string get(const char *const identifier) override;
  std::string all(const char* const query) override;
  std::string blocks(const char *const identifier, const char* const query) override;
  std::string voters(const char *const identifier, const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
