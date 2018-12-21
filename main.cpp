#include "main.h"
using namespace std;


// int main_offline(int argc, char** argv){
//
//   if (argc != 3){
//     std::cerr << "Bad args." << std::endl;
//     return -1;
//   }
//
//   Sol mysol;
//
//   Instance* to_opti= new Instance(argv[1], argv[2]);
//
//   Archive myarchive = archive_rand(500);
//   write_archive(myarchive, to_opti, "./data/result_rand.txt");
//   filter_offline(myarchive, to_opti);
//   write_archive(myarchive, to_opti, "./data/filter_rand.txt");
//
//   return 0;
// }

// int main_online(int argc, char** argv){
//
//   if (argc != 4){
//     std::cerr << "Bad args." << std::endl;
//     return -1;
//   }
//
//   Sol mysol;
//
//   Instance* to_opti= new Instance(argv[1], argv[2]);
//
//   Archive myarchive = archive_rand(1);
//   for (int i = 1; i < 500; i++){
//     Sol new_sol = random_perm(i);
//     filter_online(myarchive, new_sol, to_opti);
//   }
//   std::stringstream ss;
//   ss << "./data/online_filter_rand" << argv[3] << ".txt";
//   write_archive(myarchive, to_opti, ss.str());
//
//   return 0;
// }

int main(int argc, char** argv){

  if (argc != 3){
    std::cerr << "Bad args." << std::endl;
    return -1;
  }

  Sol mysol;

  Instance* to_opti= new Instance(argv[1], argv[2]);

  Sol new_sol = random_perm(i);
  loop_k_opt

  // Archive myarchive = archive_rand(1);
  // for (int i = 1; i < 500; i++){
  //   Sol new_sol = random_perm(i);
  //   filter_online(myarchive, new_sol, to_opti);
  // }
  // std::stringstream ss;
  // ss << "./data/online_filter_rand" << argv[3] << ".txt";
  // write_archive(myarchive, to_opti, ss.str());

  return 0;
}
