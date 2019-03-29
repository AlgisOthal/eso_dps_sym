#include "form_dpssym.h"
#include "ui_form_dpssym.h"

#include <eso_dps_sym/char_attributes.h>
#include <eso_dps_sym/rotation_prepare.h>

#include "defines.h"
#include "plot_painter.h"

FormDpsSym::FormDpsSym(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDpsSym)
{
    ui->setupUi(this);
}

FormDpsSym::~FormDpsSym()
{
    delete ui;
}

void FormDpsSym::on_pushButton_clicked()
{
    using namespace std;

    // sym
    auto dmgs = symDamage();

    //-------------

    // all damage
    {
        // calculate
        QVector< double > time( 1, 0 ), attack( 1, 0 );
        uint64_t total_dmg = 0;
        for( TakenDamage& dmg: dmgs )
        {
            if( dmg.time > ui->spinBox_time_fight->value() * 1000 )
                break;

            time.push_back( dmg.time );
            total_dmg += dmg.damage;
            attack.push_back( total_dmg );
        }

        // plot
        PlotPainter::clearGraphs( ui->customPlot_all );
        PlotPainter::paintOnePlot( ui->customPlot_all, time, attack );
    }

    //---------------------

    // dps
    {
        // calculate
        QVector< double > time( 1, 0 ), attack( 1, 0 );
        uint64_t cur_time = 0;
        uint64_t cur_dmg = 0;
        for( TakenDamage& dmg: dmgs )
        {
            if( dmg.time > ui->spinBox_time_fight->value() * 1000 )
                break;

            if( dmg.time > cur_time + 1000 )
            {
                time.push_back( cur_time );
                attack.push_back( cur_dmg );
                cur_dmg = 0;
                cur_time += 1000;
            }

            cur_dmg += dmg.damage;
        }

        // plot
        PlotPainter::clearGraphs( ui->customPlot_dps );
        PlotPainter::paintOnePlot( ui->customPlot_dps, time, attack );
    }

    // calculate total damage
    uint64_t total = 0;
    uint64_t max_time = 0;
    for( TakenDamage& dmg: dmgs )
    {
        if( dmg.time > ui->spinBox_time_fight->value() * 1000 )
            break;

        total += dmg.damage;
        max_time = max( max_time, dmg.time );
    }
    ui->spinBox_total->setValue( total );
    ui->spinBox_dps->setValue( total * 1000 / ( max_time - ui->spinBox_start->value() * 1000 ));
}

TakenDamages FormDpsSym::symDamage()
{
    CharAttributes attrs = init_attrs;

    RotationPrepare rotation;
    // buff
    rotation.skillAndWait( SkillType::resolve, 0 );

    rotation.laAndSkill( SkillType::blockade );
    rotation.laAndSkill( SkillType::twisting_path );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );

    rotation.laAndSkill( SkillType::spectral );

    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );

    rotation.laAndSkill( SkillType::spectral );

    rotation.laAndSkill( SkillType::blockade );
    rotation.laAndSkill( SkillType::twisting_path );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );

    rotation.laAndSkill( SkillType::spectral );

    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );
    rotation.laAndSkill( SkillType::swallow );

    rotation.laAndSkill( SkillType::spectral );

    rotation.laAndSkill( SkillType::impale );
    rotation.laAndSkill( SkillType::impale );
    rotation.laAndSkill( SkillType::impale );
    rotation.laAndSkill( SkillType::impale );

    DpsSym sym;
    sym.prepare( rotation );
    TakenDamages dmgs = sym.symulate( attrs );

    return dmgs;
}
