project('crepe', 'cpp', version: '0.1', default_options: ['warning_level=3', 'cpp_std=c++20'])

executable('crepe', 'src/crepe.cpp', 'src/useful.cpp', install: true)

subproject('gtest', default_options: ['warning_level=3', 'cpp_std=c++20'])
gtest_dep = dependency('gtest_main', main: true, required: false)
tests_src = [
  'src/useful.cpp', 'tests/test_useful.cpp',
]  
tests = executable('crepe-tests', tests_src, dependencies: [gtest_dep])    
test('GTest Unit Tests', tests)
