# Directory Structure:

- docs: documentation
- data: configuration and databases.
- src: This directory contains the source files for your project.
- include: This directory contains the header files for your project that are meant to be used by other parts of your project or by other projects. The myproject subdirectory is used to avoid name clashes with other libraries.
- libs: This directory contains the source files for any libraries that your project uses. Each library has its own subdirectory.
- tests: This directory contains your test files.
- deps: This directory contains any external dependencies that your project uses. Each dependency has its own subdirectory.
- build: This directory is where the compiled files will be placed. It's typically not included in the version control system.

CMakeLists.txt: This is the build configuration file.
