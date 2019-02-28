#!/bin/bash

# for i in {1..5}
# do
  # echo "./tsp data/randomA100.tsp data/randomB100.tsp $i 0.005"
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 50 3 1
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 50 3 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 50 5 1
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 50 5 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 100 3 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 100 7 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 500 3 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 500 5 10
  time ./tsp data/randomA100.tsp data/randomB100.tsp 500 7 10
  echo "-------"
  time ./tsp data/randomA100.tsp data/randomB100.tsp 500 10 10
# done
