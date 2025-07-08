# Makefile for OOP C++ Learning Repository

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Directories
BASICS_DIR = 01_basics
ENCAP_DIR = 02_encapsulation
INHERIT_DIR = 03_inheritance
POLY_DIR = 04_polymorphism
ABSTRACT_DIR = 05_abstraction
ADVANCED_DIR = 06_advanced_concepts
PATTERNS_DIR = 07_design_patterns
PROJECTS_DIR = 08_projects

# Source files
BASICS_SOURCES = $(wildcard $(BASICS_DIR)/*.cpp)
ENCAP_SOURCES = $(wildcard $(ENCAP_DIR)/*.cpp)
INHERIT_SOURCES = $(wildcard $(INHERIT_DIR)/*.cpp)
POLY_SOURCES = $(wildcard $(POLY_DIR)/*.cpp)
ABSTRACT_SOURCES = $(wildcard $(ABSTRACT_DIR)/*.cpp)
ADVANCED_SOURCES = $(wildcard $(ADVANCED_DIR)/*.cpp)
PATTERNS_SOURCES = $(wildcard $(PATTERNS_DIR)/*.cpp)
PROJECTS_SOURCES = $(wildcard $(PROJECTS_DIR)/*.cpp)

# Object files
BASICS_OBJECTS = $(BASICS_SOURCES:.cpp=.o)
ENCAP_OBJECTS = $(ENCAP_SOURCES:.cpp=.o)
INHERIT_OBJECTS = $(INHERIT_SOURCES:.cpp=.o)
POLY_OBJECTS = $(POLY_SOURCES:.cpp=.o)
ABSTRACT_OBJECTS = $(ABSTRACT_SOURCES:.cpp=.o)
ADVANCED_OBJECTS = $(ADVANCED_SOURCES:.cpp=.o)
PATTERNS_OBJECTS = $(PATTERNS_SOURCES:.cpp=.o)
PROJECTS_OBJECTS = $(PROJECTS_SOURCES:.cpp=.o)

# Executables
BASICS_EXECS = $(BASICS_SOURCES:.cpp=)
ENCAP_EXECS = $(ENCAP_SOURCES:.cpp=)
INHERIT_EXECS = $(INHERIT_SOURCES:.cpp=)
POLY_EXECS = $(POLY_SOURCES:.cpp=)
ABSTRACT_EXECS = $(ABSTRACT_SOURCES:.cpp=)
ADVANCED_EXECS = $(ADVANCED_SOURCES:.cpp=)
PATTERNS_EXECS = $(PATTERNS_SOURCES:.cpp=)
PROJECTS_EXECS = $(PROJECTS_SOURCES:.cpp=)

# Default target
all: basics encapsulation inheritance polymorphism abstraction advanced patterns projects

# Section targets
basics: $(BASICS_EXECS)
encapsulation: $(ENCAP_EXECS)
inheritance: $(INHERIT_EXECS)
polymorphism: $(POLY_EXECS)
abstraction: $(ABSTRACT_EXECS)
advanced: $(ADVANCED_EXECS)
patterns: $(PATTERNS_EXECS)
projects: $(PROJECTS_EXECS)

# Generic rule for creating executables
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up build artifacts
clean:
	rm -f $(BASICS_EXECS) $(ENCAP_EXECS) $(INHERIT_EXECS) $(POLY_EXECS) \
	      $(ABSTRACT_EXECS) $(ADVANCED_EXECS) $(PATTERNS_EXECS) $(PROJECTS_EXECS) \
	      $(BASICS_OBJECTS) $(ENCAP_OBJECTS) $(INHERIT_OBJECTS) $(POLY_OBJECTS) \
	      $(ABSTRACT_OBJECTS) $(ADVANCED_OBJECTS) $(PATTERNS_OBJECTS) $(PROJECTS_OBJECTS)

# Run specific programs
run-%: %
	./$<

# Test all programs in a section
test-basics: $(BASICS_EXECS)
	@echo "Testing basics programs..."
	@for prog in $(BASICS_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-encapsulation: $(ENCAP_EXECS)
	@echo "Testing encapsulation programs..."
	@for prog in $(ENCAP_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-inheritance: $(INHERIT_EXECS)
	@echo "Testing inheritance programs..."
	@for prog in $(INHERIT_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-polymorphism: $(POLY_EXECS)
	@echo "Testing polymorphism programs..."
	@for prog in $(POLY_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-abstraction: $(ABSTRACT_EXECS)
	@echo "Testing abstraction programs..."
	@for prog in $(ABSTRACT_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-advanced: $(ADVANCED_EXECS)
	@echo "Testing advanced programs..."
	@for prog in $(ADVANCED_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-patterns: $(PATTERNS_EXECS)
	@echo "Testing design patterns programs..."
	@for prog in $(PATTERNS_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

test-projects: $(PROJECTS_EXECS)
	@echo "Testing project programs..."
	@for prog in $(PROJECTS_EXECS); do echo "Running $$prog"; ./$$prog; echo ""; done

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build all programs"
	@echo "  basics       - Build basic concept programs"
	@echo "  encapsulation - Build encapsulation programs"
	@echo "  inheritance  - Build inheritance programs"
	@echo "  polymorphism - Build polymorphism programs"
	@echo "  abstraction  - Build abstraction programs"
	@echo "  advanced     - Build advanced concept programs"
	@echo "  patterns     - Build design pattern programs"
	@echo "  projects     - Build project programs"
	@echo "  clean        - Remove all build artifacts"
	@echo "  run-<program> - Run specific program"
	@echo "  test-<section> - Test all programs in a section"
	@echo "  help         - Show this help message"

.PHONY: all basics encapsulation inheritance polymorphism abstraction advanced patterns projects clean help \
        test-basics test-encapsulation test-inheritance test-polymorphism test-abstraction test-advanced test-patterns test-projects
