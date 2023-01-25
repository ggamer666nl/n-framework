#include <iostream>
#include <string>

using namespace std;

class dimension {
private:
    char map[20][100];

public:

    void set(unsigned short int x, unsigned short int y, char input) {
        map[x][y] = input;
    }
    void set(char input_map[20][100]) {
        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 100; y++) {
                map[x][y] = input_map[x][y];
            }
        }
    }

    char get(unsigned short int x, unsigned short int y) {
        return map[x][y];
    }

    char * get() {
        char *array_loc = *map;
        return array_loc;
    }

};

class algorithms {
public:

    void generate_random(unsigned short int x, unsigned short int y) {

    }
};

class player {
private:
    char player_skin = '!';
    unsigned short int player_move_speed;
    unsigned short int player_pos_x;
    unsigned short int player_pos_y;


public:
    void set_player_skin(char new_skin) {
        player_skin = new_skin;
    }

    void set_player_move_speed(unsigned short int new_player_speed) {
        player_move_speed = new_player_speed;
    }

    void set_pos(unsigned short int x, unsigned short int y) {
        player_pos_x = x;
        player_pos_y = y;
    }

    unsigned short int get_x() {return player_pos_x;}
    unsigned short int get_y() {return player_pos_y;}

    char get_player_skin() {return player_skin;}

    unsigned short int get_player_move_speed() {return player_move_speed;}
};
/*
class dimension_painter {
    dimension current_dimension;
public:
    dimension get() {
        return current_dimension;
    }

    dimension set(dimension input) {
        current_dimension.set(input.get());
    }
};

*/

class nxx {
private:

    static const unsigned short int max_dimensions = 3;

    dimension dimensions[max_dimensions];

    player intergrated_player;

    bool start_called = false;




    // const unsigned short int max_dimensions = 3;

    unsigned short int current_dimension = 0;

    const unsigned short int dimension_size_x = 20;
    const unsigned short int dimension_size_y = 100;


public:

    void render() {
        for (int x = 0; x < dimension_size_x; x++) {
            for (int y = 0; y < dimension_size_y; y++) {
                if (intergrated_player.get_x() == x && intergrated_player.get_y() == y) {
                    std::cout << intergrated_player.get_player_skin();
                }
                else {
                    std::cout << dimensions[current_dimension].get(x, y);
                }
            }
            std::cout << std::endl;
        }
    }

    void render_test_mode() {
        std::cout << dimensions
    }

    bool demension_up() {
        if (!(current_dimension == max_dimensions-1)) {
            current_dimension++;
            return true;
        }
        return false;
    }

    bool demension_down() {
        if (!(current_dimension == 0)) {
            current_dimension--;
            return true;
        }
        return false;
    }

    unsigned short int get_current_dimension() {
        return current_dimension;
    }

    void set_player(player new_player) {
        intergrated_player = new_player;
    }

    void set_player_move_speed(unsigned short int new_move_speed) {
        intergrated_player.set_player_move_speed(new_move_speed);
    }

    void generate_map(char to_generate) {
        for (int x = 0; x < dimension_size_x; x++) {
            for (int y = 0; y < dimension_size_y; y++) {
                dimensions[current_dimension].set(x, y, to_generate);
            }
        }
    }

    void generate_map(char to_generate, unsigned short int to_x, unsigned short int to_y) {
        if (!(to_x > dimension_size_x) && !(to_y > dimension_size_y)) {
            for (int x = 0; x < to_x; x++) {
                for (int y = 0; y < to_y; y++) {
                    dimensions[current_dimension].set(x, y, to_generate);
                }
            }
        }
    }

    void paint_dimension(unsigned short int layer_num, char layer[]) {
        for (int x = 0; x < dimension_size_y; x++) {
            dimensions[current_dimension].set(layer_num, x, layer[x]);
        }

    }

    void start();

    void end() {
        std::cout << "press enter to quit...";
        std::cin.get();
    }


};

int main()
{

    player player_test;

    player_test.set_pos(5,12);
    player_test.set_player_skin('P');
    player_test.set_player_move_speed(1);



    nxx test_game_engine;



    test_game_engine.set_player(player_test);

    test_game_engine.generate_map('&');
    test_game_engine.render();

    test_game_engine.generate_map('*');

    test_game_engine.render_test_mode();

    test_game_engine.end();



    return 0;
}
