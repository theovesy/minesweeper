#include "player.h"

Player::Player(int width, int height, int n_mine)
    : game(width, height, n_mine), m_width(width), m_height(height), game_over(false)
    {}

void Player::play()
{
    print_field();

    while (!game.won() && !game_over)
    {
        process_input();
        print_field();
    }

    if (!game_over)
        print_win();
}

void Player::print_field()
{
    std::vector<std::vector<Output_Cell>> field = game.get_field();

    for (int i = 0; i < m_width; i++)
    {
        for (int j = 0; j < m_height; j++)
        {
            switch (field[i][j].status)
            {
                case CellStatus::FLAGGED:
                    std::cout << 'f'; 
                    break;
                case CellStatus::HIDDEN:
                    std::cout << '_';
                    break;
                case CellStatus::MINE:
                    std::cout << '#';
                    break;
                case CellStatus::OPEN:
                    std::cout << field[i][j].prox;
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Player::print_win()
{
    std::cout << "You won!" << std::endl;
}

void Player::print_defeat()
{
    game_over = true;
    std::cout << "BOOM! you dead" << std::endl;
}

/*
std::string get_input()
{
    std::cout << "Input command : " << std::endl;
    std::string input = "o 1 1";
    std::cin >> input;
    return "lol";
}
*/

void Player::process_input()
{
    while (true)
    {
        std::string input_str = "test"; //get_input();
        //std::cin >> input_str;
        std::getline(std::cin, input_str);
        Input input = parse_input(input_str);
        switch (input.type)        
        {
            case InputType::OPEN:
                game.open(input.y-1, input.x-1);
                if(game.has_mine(input.y,input.x))
                    print_defeat();
                return;
            case InputType::FLAG:
                game.flag(input.y-1, input.x-1);
                return;
        }
        /*
        try
        {

        }
        catch(const std::exception& e)
        {
            std::cout << "Invalid input ! " << std::endl;
        }
        */
    }
}

// input look like : "o 10 43"
// where o is type of input (open)
// 10 and 43 are x and y coordinate of the cell
Input Player::parse_input(const std::string& input_str)
{
    Input input;
    switch (input_str[0])
    {
        case 'o':
            input.type = InputType::OPEN;
            break;
        case 'f':
            input.type = InputType::FLAG;
            break;
        default:
            input.type = InputType::INVALID;
    } 

    int between_x_y = find_space_after(1,input_str);
    int after_y = find_space_after(between_x_y,input_str);
    std::cout << input_str.substr(2, between_x_y - 2) << std::endl;
    std::cout << input_str.substr(between_x_y + 1, after_y - between_x_y - 2) << std::endl;
    input.x = std::stoi(input_str.substr(2, between_x_y - 2));
    input.y = std::stoi(input_str.substr(between_x_y, after_y - between_x_y));

    return input;
}

int Player::find_space_after(int a, const std::string& input_str)
{
    for (int i = a+1; i < input_str.size(); i++)
        if (input_str[i] == ' ')
            return i;
    return 0;
}




