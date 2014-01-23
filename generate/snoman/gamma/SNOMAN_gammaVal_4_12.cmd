titles qio_data.dat 
titles dmm.dat 
titles casl.dat 
set bank TDMM 1 word 14 to 0 
set bank TQIO 3 word 19 to 0 
set bank TQIO 3 word 5 to 1 
titles anxx_nu_0000020674_p3.dat 
titles DQXX_0000020674.dat 
file QIO 1 SNOMAN_gammaVal_4_12.root 
$mcrun 20675 
$mc_event_rate 50.00 $per_sec 
$mc_gen_run_cond $on 
$mc_num_seed_vx 1 
$mc_interaction_type   $start$$gamma 
$mc_position           $pos_point -291.78 310.03 329.38 
$mc_direction          $dir_isotropic 
$mc_energy $en_mono  4.4 
$mc_time  $tim_fixed 0.0 
$mc_miscellaneous  $misc_random_pol
$num_events 10000 
define event_loop 
call mco 
call ftt 
call ftp 
call ftu 
call qio(2) 
quit_event 
end_def 
$pegs_file  'pegs4_10.dat' 


$egs4_ds  $on 
$killvx  0 
$mcdaq_ztell    $off 
$fresnel_scat    $on 
$rayleigh_scat     $on 
$photodisintegration   $on 
@geom_belly_plate_rope 
$max_cer_ge_errors 20 
$geom_media 200 400 
$3d_pmt 
$mc_drift_attenuation $off *Me 
$mc_drift_pmt_coll $off *Me 
$pmt_var $off *Me 


@load_salt_settings 
@run_snodb 
