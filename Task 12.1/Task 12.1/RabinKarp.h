#pragma once

// Хэш-функция для строки.
int hashFunctionForString(char someString[]);

// Хэш-функция для символа.
int hashFunctionForChar(char someChar, int needPower);

// Алгоритм для нахождения индекса первого вхождения подстроки в строку.
int findIndexOfSubstring(char someString[], char substring[]);