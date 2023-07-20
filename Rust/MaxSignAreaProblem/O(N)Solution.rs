// Author John Moore
// Last Edited 20/07/2023
// This solves the common interview problem Container With Most Water" / "Max Area of Island" / "Max Area of Histogram" problem

const _WIDTH: i32 = 10; // 10 meter width
const _RANDOMSEED: i32 = 1923; // random seed for pseudo random number generator / building max height

// this function generates a pseudo random number between 1 and 10
fn pseudo_random(i: i32, input_height_length: usize) -> i32 {
    let height_length: i32 = input_height_length as i32;

    // poorly generated pseudo random number modulo 10
    return (7243 * i + 4019 + height_length) % _RANDOMSEED + 1; // return [1,10]
}

// this function generates an array of heights
fn generate_array(size: i32) -> Vec<i32> {
    let mut height = Vec::new();
    let mut i = 0;

    while i <= size {
        height.push(pseudo_random(i, height.len()));
        i = i + 1;
    }

    height
}

// this function calculates the max area between two buildings in O(n) time
fn max_sign_area(height: Vec<i32>) -> i32 {
    let mut max_area: i32 = 0;
    let mut left = 0;
    let mut right = height.len() - 1;

    // while left < right
    while left < right {
        // calculate area with minimum height between left and right
        let area = (right - left) as i32 * height[left].min(height[right]); // area between left and right using the smallest hight
        max_area = max_area.max(area); // if area > max_area, max_area = area

        if height[left] < height[right] {
            left = left + 1; // move left in one because it was smaller in height so it can't have the max area
        } else {
            right = right - 1;
        }
    }

    max_area * _WIDTH
}

fn main() {
    let num_buildings = 1000; // number of buildings / number of heights in array

    let height: Vec<i32> = generate_array(num_buildings); // generate array of heights
    println!("{:?}", height);

    // Search for Sign position
    let max_area: i32 = max_sign_area(height); // calculate max area
    println!("max_area: {}", max_area);
}
