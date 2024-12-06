#! /bin/bash

FOLDER = $(pwd)
EMSDK_FOLDER = "/datadisk1/_KDE/emsdk/"

if [ -d "$EMSDK_FOLDER"]; then
  cd emsdk_folderhow
  source ./emsdk_env.sh
  cd FOLDER
else
  echo "The EMSDK_FOLDER '$EMSDK_FOLDER' does not exist."
fi

