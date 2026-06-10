# Exam Generator System

## Overview

This project was developed in C++ as part of a Programming I course. The application allows users to create and manage a question bank and generate exams automatically based on predefined rules and constraints.

The system applies Object-Oriented Programming concepts such as classes, object relationships, vectors, encapsulation, and modular design.

## Features

### Question Management

* Create new questions.
* Assign a score value to each question.
* Add a variable number of answers.
* Support multiple correct answers.
* Automatically assign unique IDs to questions.
* Display all questions with their answers and usage count.
* Search questions by ID.

### Exam Management

* Generate exams from the question bank.
* Assign a name and maximum score to each exam.
* Store generated exams for future consultation.
* Display all created exams.
* Search exams by name.
* Delete exams and update question usage counters.

## Business Rules

* Each question can be used in a maximum of three different exams.
* Questions that exceed the usage limit are excluded from future exam generation.
* The total score of selected questions must be less than or equal to the exam score.
* Exams store references to question IDs instead of duplicating question data.
* Question IDs are generated sequentially starting from 1.

## Technologies

* C++
* Object-Oriented Programming (OOP)
* STL Vector Containers

## Project Structure

```text
Answer.cpp
Answer.h
AnswerContainer.cpp
AnswerContainer.h
CMakeLists.txt
Generator.cpp
Generator.h
Id.cpp
Id.h
IdContainer.cpp
IdContainer.h
Question.cpp
Question.h
QuestionContainer.cpp
QuestionContainer.h
Test.cpp
Test.h
TestContainer.cpp
TestContainer.h
main.cpp
```

## Learning Objectives

* Practice object-oriented design.
* Work with dynamic collections using vectors.
* Implement relationships between classes.
* Develop modular and maintainable C++ applications.
* Apply software design principles in a real-world scenario.

## Author
Aarón Guevara
Developed as an academic project for the Programming I course.
