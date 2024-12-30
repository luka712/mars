#! /bin/bash

FOLDER=$(pwd)
EMSDK_FOLDER="/datadisk1/_KDE/emsdk/"

if [ -d "$EMSDK_FOLDER" ]; then
  cd "$EMSDK_FOLDER"
  source ./emsdk_env.sh
  cd "$FOLDER" || exit
else
  echo "The EMSDK_FOLDER '$EMSDK_FOLDER' does not exist."
fi

