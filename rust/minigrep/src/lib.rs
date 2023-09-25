use std::error::Error;
use std::fs;
use std::env;   

pub struct  Config{
    pub query:String,
    pub file_path:String,
    pub ignore_case:bool
}

impl Config {
    //paser args plus
    // 也可能包含一条错误信息 &static str，不熟悉这种字符串类型的同学可以回头看看字符串章节
    // ，代码中的字符串字面量都是该类型，且拥有 'static 生命周期。
    pub fn build(args:&[String]) -> Result<Config,&'static str>{
        if args.len() < 3 {
            return Err("not enough arguments");
        }
        let query = args[1].clone();
        let file_path = args[2].clone();
        // let ignore_case_flag = env::var("IGNORE_CASE").ok();
        
        let ignore_case = env::var("IGNORE_CASE").is_ok();
    //  is_ok Result 提供的，用于检查是否有值，有就返回 true

        Ok(Config { 
            query: query, 
            file_path: file_path ,
            ignore_case:ignore_case})
    }
}

// 没有返回值 但有any类型的error 
// 因为 Result<T,E> 定义必须返回一个T和一个error
pub fn run(config:Config) -> Result<(),Box<dyn Error>>{
    println!("Searching for \"{}\"", config.query);
    println!("In file \"{}\"", config.file_path);

    let contents = fs::read_to_string(config.file_path)?;
        // .expect("Should have been able to read the file");
        // ? 运算符用于快速处理错误，并将错误传播给调用者。
        // expect 方法用于显式处理错误，并触发一个 Panic，提供指定的错误消息。
    
        //以下是用 语句返回值实现的向results中赋值
        // 说实话 合医办编程思维不一样
        let results = if config.ignore_case {
            search_case_insensitive(&config.query, &contents)
        } else {
            search(&config.query, &contents)
        };
    

    for line in results{
        println!("{}",line);
    }
    Ok(())
    // 返回一个空的
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    // let mut v:Vec<&str> = vec![];
    let mut results =Vec::new();
    for line in contents.lines() {
        if line.contains(query){
            results.push(line);
        }
    }
    return results;
}


pub fn search_case_insensitive<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    // let mut v:Vec<&str> = vec![];
    let mut results =Vec::new();
    let query = query.to_lowercase();
    for line in contents.lines() {
        if line.to_lowercase().contains(&query){
            println!("{}",line);
            results.push(line);
        }
    }
    return results;
}


#[cfg(test)]
mod tests{
    // use std::task::Context;

    use std::vec;

    // 它会导入父模块中的所有公共项到当前模块的作用域中，
    // 使得你可以直接使用这些项而不需要使用完整的路径。
    use super::*;
    #[test]
    fn case_sensitive() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
        
    }
    fn case_insensitive() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        assert_eq!(vec!["safe, fast, productive."],
                    search_case_insensitive(query, contents));
        
    }

    
// in lib.rs
    pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
        // let mut v:Vec<&str> = vec![];
        let mut results =Vec::new();

        for line in contents.lines() {
            if line.contains(query){
                println!("{}",line);
                results.push(line);
            }
        }
        return results;
    }
    
}
