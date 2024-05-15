import os
import re

def contains_md5(text):
    # 正则表达式匹配MD5值
    md5_pattern = re.compile(r'[a-fA-F0-9]{32}')
    return bool(md5_pattern.search(text))

def contains_encoded_md5(text):
    # 正则表达式匹配URL编码的空格和MD5值
    encoded_md5_pattern = re.compile(r'%20[a-fA-F0-9]{32}')
    return bool(encoded_md5_pattern.search(text))


def remove_encoded_md5_from_file(file_path):
    # 正则表达式匹配URL编码的空格和MD5值
    encoded_md5_pattern = re.compile(r'%20[a-fA-F0-9]{32}')
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()

        # 删除匹配的MD5哈希值
        modified_content = re.sub(encoded_md5_pattern, '', content)

        # 如果内容被修改，则写回文件
        if content != modified_content:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(modified_content)
            print(f'MD5 hash removed from file: {file_path}')
        else:
            print(f'No MD5 hash found in file: {file_path}')
    except Exception as e:
        print(f'Error processing file {file_path}: {e}')
def check_files_in_directory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    print(content)
                    if contains_encoded_md5(content):
                        remove_encoded_md5_from_file(file_path)
                        print(f'MD5 hash found in file: {file_path}')
            except Exception as e:
                print(f'Error reading file {file_path}: {e}')

# 替换下面的路径为你想要检查的文件夹路径
check_files_in_directory('./')