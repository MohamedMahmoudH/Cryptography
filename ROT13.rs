fn main()
{
    let mut flag: String = String::new();
    let mut res : String = String::new();

    print!("enter the flag : ");
    std::io::stdin().read_line(&mut flag).unwrap();

    for ch in flag.chars() {
        let mut temp: char = ch;
        if ch.is_alphabetic() {
            if temp.is_lowercase() {
                temp = temp.to_uppercase().next().unwrap();
            }
            match temp > 'M' {
                true  => temp = (ch as u8 - 13) as char,
                false => temp = (ch as u8 + 13) as char
            }
        }
        res.push(temp);
    }

    print!("this is the FLAG : {}",res);
}
