#!/bin/sh
sh build.sh

(cd build/tests/unit_tests && ./airwatcher_unit_tests)
(cd build/tests/validation_tests && ./airwatcher_validation_tests)