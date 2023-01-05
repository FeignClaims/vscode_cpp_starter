include(${CMAKE_CURRENT_LIST_DIR}/ProjectOptions.cmake)

set(ENABLE_CONAN_DEFAULT ON)

# not supportted on my platform (MacOS Ventura, M1 2020)
if(${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
  set(ENABLE_SANITIZER_ADDRESS_DEFAULT OFF)
  set(ENABLE_SANITIZER_UNDEFINED_BEHAVIOR_DEFAULT OFF)
endif()

# -----------------
# for non-project
set(ENABLE_CLANG_TIDY_DEVELOPER_DEFAULT OFF)
set(ENABLE_CPPCHECK_DEVELOPER_DEFAULT OFF)

# -----------------
set(WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT OFF)

dynamic_project_options(
  MSVC_WARNINGS
  /W4 # Baseline reasonable warnings
  /permissive- # standards conformance mode for MSVC compiler.
  /w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss of data
  /w14254 # 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
  /w14263 # 'function': member function does not override any base class virtual member function
  /w14265 # 'classname': class has virtual functions, but destructor is not virtual instances of this class may not be destructed correctly
  /w14287 # 'operator': unsigned/negative constant mismatch
  /w14296 # 'operator': expression is always 'boolean_value'
  /w14311 # 'variable': pointer truncation from 'type1' to 'type2'
  /w14545 # expression before comma evaluates to a function which is missing an argument list
  /w14546 # function call before comma missing argument list
  /w14547 # 'operator': operator before comma has no effect; expected operator with side-effect
  /w14549 # 'operator': operator before comma has no effect; did you intend 'operator'?
  /w14555 # expression has no effect; expected expression with side- effect
  /w14619 # pragma warning: there is no warning number 'number'
  /w14640 # Enable warning on thread un-safe static member initialization
  /w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
  /w14905 # wide string literal cast to 'LPSTR'
  /w14906 # string literal cast to 'LPWSTR'
  /w14928 # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
  /we4289 # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope

  CLANG_WARNINGS
  -Wall
  -Wextra # reasonable and standard
  -Wextra-semi # warn about semicolon after in-class function definition
  -Wcast-align # warn for potential performance problem casts
  -Wconversion # warn on type conversions that may lose data
  -Wdouble-promotion # warn if float is implicit promoted to double
  -Wformat=2 # warn on security issues around functions that format output (ie printf)
  -Wfloat-equal # warn on comparing floating point with == or !=
  # -Wglobal-constructors # warn on declare global or static variables with dynamic constructors
  -Wimplicit-fallthrough # warn on statements that fallthrough without an explicit annotation
  -Wmisleading-indentation # warn if indentation implies blocks where blocks do not exist
  -Wmissing-noreturn # warn about functions that might be candidates for [[noreturn]].
  -Wnon-virtual-dtor # warn the user if a class with virtual functions has a non-virtual destructor. This helps catch hard to track down memory errors
  -Wnull-dereference # warn if a null dereference is detected
  -Wold-style-cast # warn for c-style casts
  -Woverloaded-virtual # warn if you overload (not override) a virtual function
  -Wpacked # warn if a structure is given the packed attribute, but the packed attribute has no effect on the layout or size of the structure.
  -Wpedantic # warn if non-standard C++ is used
  -Wpointer-arith
  -Wshadow # warn the user if a variable declaration shadows one from a parent context
  -Wsign-conversion # warn on sign conversions
  -Wunused # warn on anything being unused
  -Wundef # warn if an undefined identifier is evaluated in an #if directive.
  -ftemplate-backtrace-limit=0

  GCC_WARNINGS
  -Wall
  -Wextra
  -Wextra-semi
  -Wcast-align
  -Wconversion
  -Wdisabled-optimization
  -Wdouble-promotion
  -Wduplicated-cond # warn if if / else chain has duplicated conditions
  -Wduplicated-branches # warn if if / else branches have duplicated code
  -Wformat=2
  -Wfloat-equal
  -Wimplicit-fallthrough
  -Winvalid-pch # warn if a precompiled header is found in the search path but cannot be used.
  -Wmisleading-indentation
  -Wmissing-format-attribute # Warn about function pointers that might be candidates for format attributes.
  -Wmissing-include-dirs # warn if a user-supplied include directory does not exist.
  -Wmissing-noreturn
  -Wlogical-op # warn about logical operations being used where bitwise were probably wanted
  -Wnon-virtual-dtor
  -Wnull-dereference
  -Wold-style-cast
  -Woverloaded-virtual
  -Wpedantic
  -Wpointer-arith
  -Wredundant-decls # warn if anything is declared more than once in the same scope, even in cases where multiple declaration is valid and changes nothing.
  -Wshadow
  -Wsign-conversion
  -Wswitch-enum
  -Wundef
  -Wunused
  -Wuseless-cast # warn if you perform a cast to the same type

  CPPCHECK_OPTIONS
  --enable=style,performance,warning,portability
  --inline-suppr
  --suppress=cppcheckError # We cannot act on a bug/missing feature of cppcheck
  --suppress=internalAstError
  --suppress=unmatchedSuppression # if a file does not have an internalAstError, we get an unmatchedSuppression error
  --suppress=passedByValue
  --suppress=syntaxError
  --inconclusive
)

include(${CMAKE_CURRENT_LIST_DIR}/SymlinkCompileCommands.cmake)
