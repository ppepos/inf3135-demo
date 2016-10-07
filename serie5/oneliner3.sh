#!/bin/bash
git log | grep "Author: " | sort | uniq
