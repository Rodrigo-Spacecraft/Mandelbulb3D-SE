use mb3d::formulas::Formula;
fn main() {
    for analytic in [false, true] {
        for point in [[0.1, 0.1, 0.1, 1.0], [0.8, -0.3, 0.2, 1.0]] {
            let run = |min_r| {
                let mut v = point;
                Formula::AmazingBox {scale:1.7015625,min_r,fold:0.3046875}
                    .iterate(&mut v,&mut [0.0;4],0.0,analytic);
                v
            };
            assert_eq!(run(-0.5890625), run(0.0));
            assert_ne!(run(-0.5890625), run(0.5890625));
        }
    }
    println!("Negative Min R matches the original clamp in both iteration paths");
}
