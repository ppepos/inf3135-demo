#!/bin/bash
git log | grep "Author: " | sort | sed -e 's/Author: //' | sed -e 's/ <.*//' | uniq
