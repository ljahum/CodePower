use std::fs;
// use std::io;
use std::path::{Path,PathBuf};
// use std::string;
use std::io::{BufReader, BufRead};

fn list_files_recursively(path: &Path) -> Result<Vec<PathBuf>, std::io::Error> {
    let mut files = Vec::new();

    if path.is_dir() {
        for entry in fs::read_dir(path)? {
            let entry = entry?;
            let file_type = entry.file_type()?;
            if file_type.is_file() {
                files.push(entry.path());
            } else if file_type.is_dir() {
                files.extend(list_files_recursively(&entry.path())?);
            }
        }
    } else {
        // 如果传入的路径本身就是文件，则直接添加
        files.push(path.to_path_buf());
    }

    Ok(files)
}
fn read_file_to_lines<P>(file_path: P) -> Result<Vec<String>, std::io::Error>
where
    P: AsRef<Path>,
{
    let file = fs::File::open(file_path)?;
    let reader = BufReader::new(file);

    let lines = reader.lines().collect::<Result<Vec<_>, _>>()?;

    Ok(lines)
}
fn main() -> Result<(), std::io::Error> {

    let file_path = r"D:\MyZone\githubRepos\CodePower\rust\pathScannner\src\word_list.txt";
    let lines = read_file_to_lines(file_path)?;
    println!("检索字段:");
    for line in lines.clone() {
        println!("{}", line);
    }
    println!("============ 结 果 ===============");


    // 要检索的字段
    let substrings_to_find = lines;
    // 目标文件夹
    let dir_path = Path::new("./data");
    let files = list_files_recursively(dir_path)?;

    for file in files {
        let tmp:String =  file.display().to_string().clone();
        // println!("{}", file.display());
        let all_found = substrings_to_find.iter().all(|substring| tmp.contains(substring));

        if all_found{
            println!("{}",tmp);
        }
        
        
    }

    Ok(())
}