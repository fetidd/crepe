project('crepe', 'cpp', version: '0.1', default_options: ['warning_level=3', 'cpp_std=c++23'])
subproject('gtest', default_options: ['warning_level=3', 'cpp_std=c++23'])
subproject('fmt', default_options: ['warning_level=3', 'cpp_std=c++23'])

### APPLICATION ###
src = [
  'src/crepe.cpp',
  'src/useful.cpp',
  'src/crepe_config.cpp',
  'src/error.cpp',
]
src_deps = [
  dependency('fmt')
]
executable('crepe', src, dependencies: src_deps, install: true, cpp_args: '/std:c++latest')

### UNITTESTS ###
gtest_dep = dependency('gtest_main', main: true, required: false)
tests_src = [
  'src/useful.cpp', 'tests/test_useful.cpp',
  'src/crepe_config.cpp', 'tests/test_crepe_config.cpp',
  'src/error.cpp', 
]
test_deps = [
  gtest_dep
] + src_deps
tests = executable('crepe-tests', tests_src, dependencies: test_deps, cpp_args: '/std:c++latest')
test('GTest Unit Tests', tests)
