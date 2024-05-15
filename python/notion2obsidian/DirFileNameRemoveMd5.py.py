import os
import re


import re

def contains_md5(s):
    # 正则表达式匹配32个字符长的MD5值
    md5_pattern = re.compile(r'\b[0-9a-fA-F]{32}\b')
    # 搜索字符串中的MD5值
    if md5_pattern.search(s):
        return True
    else:
        return False
def is_md5(s):
    # 检查字符串是否为MD5值，MD5值由32个十六进制字符组成
    return re.match(r'^[0-9a-f]{32}$', s, re.I) is not None

def remove_md5_value(name):
    # 移除名称中的MD5值
    if contains_md5(name):
        # print(name)
        # print(name[:-3-32-1]+name[-3:])
        parts = name.split()
        # print(parts)
        # new_parts = name[:-3-32-1]+name[-3:]
        new_parts = name[:-3-32-1]+name[-3:]
        return name[:-3-32-1]+name[-3:]
    else:
        return name
def remove_md5_value_dir(name):
    # 移除名称中的MD5值
    if contains_md5(name):
        parts = name.split()
        # print(parts)
        # new_parts = name[:-3-32-1]+name[-3:]
        new_parts = name[:-32-1]+name[-3:]
        return name[:-32-1]
    else:
        return name

def process_file_or_dir(path, is_file):
    # 检查文件或目录名中是否包含MD5值
    
    original_name = os.path.basename(path)
    # print("original_name",original_name)
    if(is_file):
        new_name = remove_md5_value(original_name)
    else:
        new_name = remove_md5_value_dir(original_name)
    # print("new_name",new_name)
    # 如果名称发生了变化，重命名文件或目录
    if new_name != original_name:
        new_path = os.path.join(os.path.dirname(path), new_name)
        os.rename(path, new_path)
        print(f'Renamed {"file" if is_file else "directory"}: {original_name.encode()} to {new_name.encode()}')
        print(f'Renamed {"file" if is_file else "directory"}: {original_name} to {new_name}')

def process_directory(directory):
    # 遍历目录中的文件和子目录
    for entry in os.listdir(directory):
        full_path = os.path.join(directory, entry)
        if os.path.isfile(full_path):
            
            process_file_or_dir(full_path, True)
        elif os.path.isdir(full_path):
            process_directory(full_path)  # 递归处理子目录

# 从当前目录开始递归处理所有文件和目录
current_directory = os.getcwd()
for root, dirs, files in os.walk(current_directory):
    for dir in dirs:
        full_dir_path = os.path.join(root, dir)
        process_file_or_dir(full_dir_path, False)
    for file in files:
        
        full_file_path = os.path.join(root, file)
        process_file_or_dir(full_file_path, True)