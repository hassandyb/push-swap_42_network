# Push_swap

Because Swap_push isn’t as natural

## Summary

The Push_swap project focuses on sorting data using two stacks and a limited set of instructions. Your task is to sort integers using the minimum number of operations by implementing efficient algorithms.



## Contents

1. [Foreword](#foreword)
2. [Introduction](#introduction)
3. [Objectives](#objectives)
4. [Common Instructions](#common-instructions)
5. [Mandatory Part](#mandatory-part)
   - [The Rules](#the-rules)
   - [Example](#example)
   - [The "push_swap" Program](#the-push_swap-program)
   - [Benchmark](#benchmark)
6. [Bonus Part](#bonus-part)
7. [Submission and Peer-Evaluation](#submission-and-peer-evaluation)

## Foreword

This project involves implementing sorting algorithms using a custom set of instructions. The goal is to produce the smallest list of instructions possible for sorting integers in ascending order.

## Introduction

The Push_swap project requires you to sort a stack of integers using two stacks and a defined set of instructions. Your program, `push_swap`, should determine the minimal sequence of instructions needed to sort the integers.

## Objectives

- **Understand Sorting Algorithms**: Gain experience with sorting algorithms and their complexities.
- **Optimize Operations**: Implement algorithms that minimize the number of operations required.
- **Handle Edge Cases**: Manage various configurations of integer inputs efficiently.

## Common Instructions

- **Language**: C
- **Norm Compliance**: Adhere to the coding standard norms.
- **Memory Management**: Avoid leaks and properly manage allocated memory.
- **Makefile Requirements**: Include rules for `NAME`, `all`, `clean`, `fclean`, and `re`.
- **Submission Requirements**: Ensure all files, including Makefile and source files, are submitted properly.

## Mandatory Part

### The Rules

- **Stacks**: You have two stacks, `a` and `b`.
- **Initial State**: Stack `a` contains integers (positive and/or negative, without duplicates). Stack `b` is initially empty.
- **Goal**: Sort stack `a` in ascending order using the following operations:
  - `sa` (swap a): Swap the top two elements of stack `a`.
  - `sb` (swap b): Swap the top two elements of stack `b`.
  - `ss`: Perform `sa` and `sb` simultaneously.
  - `pa` (push a): Move the top element of stack `b` to stack `a`.
  - `pb` (push b): Move the top element of stack `a` to stack `b`.
  - `ra` (rotate a): Shift all elements of stack `a` up by 1.
  - `rb` (rotate b): Shift all elements of stack `b` up by 1.
  - `rr`: Perform `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shift all elements of stack `a` down by 1.
  - `rrb` (reverse rotate b): Shift all elements of stack `b` down by 1.
  - `rrr`: Perform `rra` and `rrb` simultaneously.
