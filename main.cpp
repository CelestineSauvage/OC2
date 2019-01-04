#include "main.h"
using namespace std;


// int main(int argc, char** argv){
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

// int main(int argc, char** argv){
//
//   if (argc != 4){
//     std::cerr << "Bad args." << std::endl;
//     return -1;
//   }
//
//   Sol mysol;write_archive(myarchive, to_opti, "./data/result_rand.txt");
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

  if (argc != 4){
    std::cerr << "Bad args." << std::endl;
    return -1;
  }

  std::istringstream iss( argv[3] );
  int val;

  if ( iss >> val ){
    Sol mysol;

    Instance* to_opti= new Instance(argv[1], argv[2]);
    Archive myarchive = genere_scalar(val, 0.0, 2.0, 500, to_opti);

    std::stringstream ss;

    ss << "./data/res_no_filter_scalar_" << argv[3] << ".txt";
    write_archive(myarchive, to_opti, ss.str());

    filter_offline(myarchive, to_opti);

    // ss << "./data/res_filter_scalar_" << argv[3] << ".txt";
    // write_archive(myarchive, to_opti, ss.str());
  }

  return 0;
}
