#pragma once
#include <iostream>
#include <string>

template <typename T>
void	display(T element);

template <typename T1, typename T2, typename Func>
void	iter(T1 *array, T2 len, Func display);