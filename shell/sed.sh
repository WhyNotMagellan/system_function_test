#!/bin/bash
source common.sh

# 获取指定匹配行
function test_for_match() {
	cmds=(	"seq 10 | sed -n '1,2p'"  				#取指定行
			"seq 10 | sed -n '1,/[3-4]/p'"			#取正则匹配的行
			"seq 10 | sed -n '/[2-3]/,/[3-4]/!p'" 	#去除匹配的行
			)

	for cmd in "${cmds[@]}";
	do
		run_cmd "$cmd"
	done
}

# main
test_for_match