// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
type NodeT = Option<Rc<RefCell<TreeNode>>>;
use std::cmp::max;

impl Solution {
    pub fn print_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<String>> {

        fn tree_height(root: &NodeT) -> u32 {
            match root {
                None => 0,
                Some(node) => {
                    let node = node.borrow();
                    max(tree_height(&node.left), tree_height(&node.right)) + 1
                }
            }
        }

        fn pop_mat(root: &NodeT, mat: &mut Vec<Vec<String>>,
                   h: u32, r: u32, c: u32, is_lc: bool) {
                    match root {
                        None => {}
                        Some(node) => {
                            let c = if r == 0 {
                                2_u32.pow(h-1) - 1
                            }
                            else if is_lc {
                                c - 2_u32.pow(h - r - 1)
                            }
                            else {
                                c + 2_u32.pow(h - r - 1)
                            };
                            mat[r as usize][c as usize] = format!("{}", node.borrow().val);
                            pop_mat(&node.borrow().left, mat, h, r + 1, c , true);
                            pop_mat(&node.borrow().right, mat, h, r + 1, c, false);
                        }
                    }
        }

        let mut ht = tree_height(&root);
        let nc = 2_usize.pow(ht)-1;
        let mut mat = vec![vec![String::new(); nc]; (ht as usize)];

        pop_mat(&root, &mut mat, ht, 0, 0, true);
        mat
    }
}
