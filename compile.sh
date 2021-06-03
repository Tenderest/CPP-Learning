#!/bin/bash

op_num=$# # 参数个数
min=1
execute_filename=""
filename=$1 # 文件名
filenames="" # 多文件名
base_name=${filename#*.} # 去前缀名，取后缀
# 使用 for 组合多文件名
for arr_filename in "$*"; do
	# echo $arr_filename
	filenames+=$arr_filename
done
# 对字符串做处理，去掉后面的 后缀和数量
# length=${#filenames}
# filenames=${filenames:0:$length-6}
# echo $filenames

execute_file() {
	# ./out/$1
	./out/$execute_filename
}

compile_c() {
	# compile c file
	cfile=$(basename $filename .c)
	execute_filename=$cfile".out"
	echo "编译的文件名："$filenames
	echo "执行的文件名："$execute_filename
	gcc $filenames -o ./out/$execute_filename -std=c11
	# ./out/$execute_filename
}

compile_cpp() {
	# compile c++ file
	cppfile=$(basename $filename .cpp)
	execute_filename=$cppfile".out"
	echo "编译的文件名："$filenames
	echo "执行的文件名："$execute_filename
	g++ $filenames -o ./out/$execute_filename -std=c++11
	# ./out/$execute_filename
}

compile() {
	echo "编译动作开始"
	# ...
	# if [ $2 -gt $min ]
	if [ $op_num -gt $min ]
	then
		echo "... 多个文件"
		# if [ $1 == "c" ]
		if [ $base_name == "c" ]
		then
			#c compile
			compile_c $*
		else
			#cpp compile
			compile_cpp $*
		fi
	else
		echo "... 1 个文件"
		# if [ $1 == "c" ]
		if [ $base_name == "c" ]
		then
			#c compile
			# echo "cccc"
			# cfile=$(basename $filename .c)
			# gcc $filename -o ./out/$cfile.out -std=c20; ./out/$cfile.out
			compile_c $*
		else
			#cpp compile
			#echo $base_name
			# cppfile=$(basename $filename .cpp)
			# g++ $filename -o ./out/$cppfile.out -std=c++11; ./out/$cppfile.out
			compile_cpp $*
		fi
	fi
	echo "编译动作结束"
}

# compile $base_name $op_num
compile
echo ""
echo "-- Start"
execute_file
echo "-- Stop"


# if [ $base_name == "c" ] then
		# 	#c compile
		# 	echo "cccc"
		# 	cfile=$(basename $filename .c)
		# 	gcc $filename -o ./out/$cfile.out -std=c20; ./out/$cfile.out
		# else
		# 	#cpp compile
		# 	#echo $base_name
		# 	cppfile=$(basename $filename .cpp)
		# 	g++ $filename -o ./out/$cppfile.out -std=c++11; ./out/$cppfile.out
		# fi