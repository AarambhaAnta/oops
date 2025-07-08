# Git Commit Convention for OOP Learning

## 📝 Commit Message Format

```bash
<type>(<scope>): <subject>

[optional body]

[optional footer]
```

## 🏷️ Types

### Learning-Specific Types

- **`learn`** - Implementing learning exercises, completing TODOs
- **`solve`** - Solving problems or challenges
- **`practice`** - Practice implementations or variations
- **`review`** - Code review, refactoring, or improvements
- **`experiment`** - Trying new approaches or experimenting

### Standard Types

- **`feat`** - New feature or major implementation
- **`fix`** - Bug fixes or corrections
- **`docs`** - Documentation updates
- **`style`** - Code style changes (formatting, no logic change)
- **`refactor`** - Code refactoring without changing functionality
- **`test`** - Adding or updating tests
- **`chore`** - Maintenance tasks (build, dependencies, etc.)

## 🎯 Scopes

### Section-Based Scopes

- **`basics`** - 01_basics/ files
- **`encapsulation`** - 02_encapsulation/ files
- **`inheritance`** - 03_inheritance/ files
- **`polymorphism`** - 04_polymorphism/ files
- **`abstraction`** - 05_abstraction/ files
- **`advanced`** - 06_advanced_concepts/ files
- **`patterns`** - 07_design_patterns/ files
- **`projects`** - 08_projects/ files

### File-Specific Scopes

- **`class-object`** - class_and_object.cpp
- **`constructor`** - constructor_destructor.cpp
- **`static`** - static_members.cpp
- **`friend`** - friend_function.cpp
- **`data-hiding`** - data_hiding.cpp
- **`getter-setter`** - getter_setter.cpp
- **`invariants`** - class_invariants.cpp
- **`single-inherit`** - single_inheritance.cpp
- **`multiple-inherit`** - multiple_inheritance.cpp
- **`multilevel-inherit`** - multilevel_inheritance.cpp
- **`diamond`** - diamond_problem.cpp
- **`overloading`** - function_overloading.cpp
- **`operators`** - operator_overloading.cpp
- **`virtual`** - virtual_functions.cpp
- **`abstract`** - abstract_classes.cpp
- **`adt`** - abstract_data_types.cpp
- **`interfaces`** - interfaces.cpp
- **`raii`** - raii.cpp
- **`exceptions`** - exception_handling.cpp
- **`templates`** - templates.cpp
- **`move-semantics`** - move_semantics.cpp
- **`singleton`** - singleton.cpp
- **`factory`** - factory.cpp
- **`observer`** - observer.cpp
- **`strategy`** - strategy.cpp
- **`decorator`** - decorator.cpp
- **`library-mgmt`** - library_management.cpp
- **`banking`** - banking_system.cpp
- **`student-mgmt`** - student_management.cpp
- **`game-engine`** - game_engine.cpp

## 📋 Examples

### Learning Progress Examples

```bash
# Starting a new concept
learn(basics): implement basic Student class structure

# Completing TODO items
learn(class-object): add constructor and display methods

# Solving challenges
solve(inheritance): implement Vehicle-Car hierarchy with proper constructor chaining

# Practicing variations
practice(polymorphism): add Triangle class to Shape hierarchy

# Reviewing and improving
review(encapsulation): improve data validation in Product class setters
```

### Implementation Examples

```bash
# Major implementations
feat(patterns): implement complete Observer pattern with news system

# Bug fixes
fix(virtual): correct virtual destructor implementation

# Adding functionality
learn(templates): implement generic Stack class with type safety

# Refactoring
refactor(banking): extract Transaction class for better separation

# Documentation
docs(readme): add section on polymorphism concepts
```

### Project Examples

```bash
# Starting projects
feat(library-mgmt): initialize library management system structure

# Adding features
learn(banking): implement account hierarchy with inheritance

# Completing milestones
solve(student-mgmt): complete grade management with composition

# Testing implementations
test(game-engine): add collision detection testing
```

## 🎨 Subject Line Guidelines

1. **Use imperative mood** ("add", "implement", "fix", not "added", "implemented", "fixed")
2. **Keep it under 50 characters**
3. **Don't end with period**
4. **Be specific about what you learned/implemented**

### Good Examples

- `learn(basics): implement Student class with encapsulation`
- `solve(diamond): resolve ambiguity using virtual inheritance`
- `practice(operators): add comparison operators to Complex class`
- `review(patterns): improve Singleton thread safety`

### Bad Examples

- `learn(basics): stuff` (too vague)
- `learn(basics): implemented the entire Student class with all methods and proper encapsulation.` (too long)
- `learn(basics): Added student class.` (wrong tense)

## 📖 Body Guidelines (Optional)

Use the body to explain:

- **What you learned** from implementing this
- **Challenges faced** and how you solved them
- **Key concepts** demonstrated
- **Next steps** or related concepts to explore

### Example with Body

```bash
learn(virtual): implement Shape hierarchy with polymorphism

- Created abstract Shape base class with pure virtual methods
- Implemented Circle, Rectangle, and Triangle derived classes
- Demonstrated runtime polymorphism with Shape pointer array
- Key learning: virtual functions enable dynamic method dispatch

Next: Explore virtual destructors and abstract classes
```

## 🚀 Quick Reference

### Common Commit Patterns

```bash
# Starting a new file
learn(scope): initialize [concept] implementation

# Completing basic structure
learn(scope): implement basic [class] structure

# Adding methods/features
learn(scope): add [method/feature] to [class]

# Solving problems
solve(scope): implement [specific solution]

# Fixing issues
fix(scope): correct [specific issue]

# Completing sections
learn(scope): complete [concept] implementation

# Major milestones
feat(scope): complete [major feature/project]
```

### Section Completion Pattern

```bash
# When completing entire sections
learn(basics): complete all fundamental OOP concepts
learn(inheritance): master single, multiple, and multilevel inheritance
learn(polymorphism): implement all polymorphism types
```

## 🏆 Milestone Commits

Mark significant learning milestones:

```bash
feat(basics): complete OOP fundamentals section
feat(inheritance): master inheritance concepts
feat(polymorphism): achieve runtime polymorphism mastery
feat(patterns): implement all design patterns
feat(projects): complete comprehensive banking system
```

## 📊 Progress Tracking

Use consistent patterns to track your learning progress:

```bash
# Daily progress
learn(encapsulation): day 1 - implement data hiding concepts
learn(encapsulation): day 2 - master getter/setter patterns

# Weekly reviews
review(week-1): refactor basics section implementations
review(week-2): improve inheritance hierarchy designs
```

This convention will help you maintain a clear, professional commit history that documents your learning journey effectively! 🎯
