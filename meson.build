project('crepe', 'cpp', version: '0.1', default_options: ['warning_level=3', 'cpp_std=c++20'])
subproject('gtest', default_options: ['warning_level=3', 'cpp_std=c++20'])
subproject('fmt', default_options: ['warning_level=3', 'cpp_std=c++20'])

### APPLICATION ###
src = [
  'src/crepe.cpp',
  'src/useful.cpp',
  'src/crepe_config.cpp',
]
src_deps = [
  dependency('fmt')
]
executable('crepe', src, dependencies: src_deps, install: true)

### UNITTESTS ###
gtest_dep = dependency('gtest_main', main: true, required: false)
tests_src = [
  'src/useful.cpp', 'tests/test_useful.cpp',
  'src/crepe_config.cpp', 'tests/test_crepe_config.cpp',
]
test_deps = [
  gtest_dep
] + src_deps
tests = executable('crepe-tests', tests_src, dependencies: test_deps)
test('GTest Unit Tests', tests)
