cmake_minimum_required(VERSION 4.2)
project(Test_Generator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Test_Generator
        Answer.cpp
        Answer.h
        AnswerContainer.cpp
        AnswerContainer.h
        Generator.cpp
        Generator.h
        Id.cpp
        Id.h
        IdContainer.cpp
        IdContainer.h
        main.cpp
        Question.cpp
        Question.h
        QuestionContainer.cpp
        QuestionContainer.h
        Test.cpp
        Test.h
        TestContainer.cpp
        TestContainer.h)
