//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2019
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "tl_writer_dotnet.h"

#include "td/tl/tl_config.h"
#include "td/tl/tl_generate.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  td::tl::tl_config config_td = td::tl::read_tl_config_from_file(argv[1]);

  td::tl::write_tl_to_file(config_td, "auto/tl/TdDotNetApi.cpp",
                           td::tl::TlWriterDotNet("TdApi", false, "#include \"TdDotNetApi.h\"\n\n"));
  td::tl::write_tl_to_file(config_td, "auto/tl/TdDotNetApi.h",
                           td::tl::TlWriterDotNet("TdApi", true, ""));
}
