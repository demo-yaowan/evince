#!/bin/bash

page() {
    if [[ $# != 1 ]]; then
        echo "usage: page [up | down]"
    fi
    local pid=$(ps -ef | grep "/usr/bin/evince --new-window" | grep -v grep | awk '{printf("%s", $2)}')
    if [[ $pid == "" ]]; then
        echo -e "no proc."
        return
    fi
    echo "pid:${pid}"
    if [[ $1 == "up" ]]; then
        kill -34 $pid
    elif [[ $1 == "down" ]]; then
        kill -35 $pid
    fi
}

page "$@"
