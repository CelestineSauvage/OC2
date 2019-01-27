#include "main.h"
using namespace std;


// int main(int argc, char** argv){
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
//   std::istringstream iss( argv[3] );
//   int pop;
//
//   std::stringstream ss1;
//   std::stringstream ss2;
//
//   ss1 << "./data/result_rand_" << argv[3] << ".txt";
//   ss2 << "./data/filter_rand" << argv[3] << ".txt";
//
//   if ( iss >> pop){
//
//     Archive myarchive = archive_rand_seed(pop);
//     // write_archive(myarchive, to_opti, ss1.str());
//     filter_offline(myarchive, to_opti);
//     // write_archive(myarchive, to_opti, ss2.str());
//   }
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
//   std::istringstream iss( argv[3] );
//   int pop;
//
//   if ( iss >> pop){
//
//     std::stringstream ss2;
//
//     Sol mysol;
//
//     Instance* to_opti= new Instance(argv[1], argv[2]);
//
//     Archive myarchive = archive_rand(1);
//     for (int i = 1; i < pop; i++){
//       Sol new_sol = random_perm_seed(i);
//       filter_online(myarchive, new_sol, to_opti);
//     }
//     ss2 << "./data/onlinefilter_rand" << argv[3] << ".txt";
//     // write_archive(myarchive, to_opti, ss2.str());
//   }
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
    // Archive myarchive = genere_scalar(val, 0.1, 2.0, 500, to_opti);
     Archive myarchive = genere_scalar2(5, 0.1, to_opti);

    std::stringstream ss;


    // ss << "./data/res_no_filter_scalar_" << argv[3] << ".txt";
    // write_archive(myarchive, to_opti, ss.str());

    ss << "./data/res_filter_scalar_" << argv[3] << ".txt";
    write_archive(myarchive, to_opti, ss.str());

  }

  return 0;
}


// int main(int argc, char** argv){
//   if (argc != 3){
//     std::cerr << "Bad args." << std::endl;
//     return -1;
//   }
//
//   Instance* to_opti= new Instance(argv[1], argv[2]);
//   Archive myarchive = genere_pareto(3, 300, to_opti);
// }
